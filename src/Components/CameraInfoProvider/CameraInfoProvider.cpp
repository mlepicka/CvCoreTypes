/*!
 * \file
 * \brief
 * \author Maciej Stefańczyk [maciek.slon@gmail.com]
 */

#include <memory>
#include <string>

#include "CameraInfoProvider.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace CameraInfoProvider {

CameraInfoProvider::CameraInfoProvider(const std::string & name) :
		Base::Component(name),
		width("width", 640),
		height("height", 480),
		camera_matrix("camera_matrix", cv::Mat(cv::Mat::eye(3, 3, CV_32FC1))),
		dist_coeffs("dist_coeffs", cv::Mat(cv::Mat::ones(1, 5, CV_32FC1)))
{
	width.addConstraint("0");
	width.addConstraint("1280");
	registerProperty(width);

	height.addConstraint("0");
	height.addConstraint("1280");
	registerProperty(height);

	registerProperty(camera_matrix);

	registerProperty(dist_coeffs);
}

CameraInfoProvider::~CameraInfoProvider() {
}

void CameraInfoProvider::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	// Register data streams
	registerStream("out_camerainfo", &out_camerainfo);

	// Register handlers
	h_generate_data.setup(boost::bind(&CameraInfoProvider::generate_data, this));
	registerHandler("generate_data", &h_generate_data);
	addDependency("generate_data", NULL);

	CLOG(LNOTICE) << "CameraMatrix: " << camera_matrix;
}

bool CameraInfoProvider::onInit() {

	return true;
}

bool CameraInfoProvider::onFinish() {
	return true;
}

bool CameraInfoProvider::onStop() {
	return true;
}

bool CameraInfoProvider::onStart() {
	return true;
}

void CameraInfoProvider::generate_data() {
	camera_info.setWidth(width);
	camera_info.setHeight(height);
	camera_info.setCameraMatrix(camera_matrix);
	camera_info.setDistCoeffs(dist_coeffs);

	out_camerainfo.write(camera_info);
}



} //: namespace CameraInfoProvider
} //: namespace Processors
