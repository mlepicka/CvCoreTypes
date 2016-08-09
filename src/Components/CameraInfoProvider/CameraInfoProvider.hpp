/*!
 * \file
 * \brief
 * \author Maciej Stefańczyk [maciek.slon@gmail.com]
 */

#ifndef CAMERAINFOPROVIDER_HPP_
#define CAMERAINFOPROVIDER_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"

#include <Types/CameraInfo.hpp>
#include <Types/MatrixTranslator.hpp>

namespace Processors {
namespace CameraInfoProvider {

/*!
 * \class CameraInfoProvider
 * \brief CameraInfoProvider processor class.
 *
 * Emits CameraInfo messages
 */
class CameraInfoProvider: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	CameraInfoProvider(const std::string & name = "CameraInfoProvider");

	/*!
	 * Destructor
	 */
	virtual ~CameraInfoProvider();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();

	// Data streams
	Base::DataStreamOut<Types::CameraInfo> out_camerainfo;

	Base::DataStreamIn<Types::CameraInfo, Base::DataStreamBuffer::Newest> in_camerainfo;

	// Handlers
	Base::EventHandler2 h_generate_data;
	Base::EventHandler2 h_update_params;
	Base::EventHandler2 h_reload_file;

	// Handlers
	void generate_data();
	void update_params();
	void reload_file();

	Base::Property<int> width;
	Base::Property<int> height;
	Base::Property<cv::Mat, Types::MatrixTranslator> camera_matrix;
	Base::Property<cv::Mat, Types::MatrixTranslator> dist_coeffs;
	Base::Property<cv::Mat, Types::MatrixTranslator> rectificaton_matrix;
	Base::Property<cv::Mat, Types::MatrixTranslator> projection_matrix;
	Base::Property<cv::Mat, Types::MatrixTranslator> rotation_matrix;
	Base::Property<cv::Mat, Types::MatrixTranslator> translation_matrix;
	Base::Property<std::string> data_file;
	Types::CameraInfo camera_info;

};

} //: namespace CameraInfoProvider
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("CameraInfoProvider", Processors::CameraInfoProvider::CameraInfoProvider)

#endif /* CAMERAINFOPROVIDER_HPP_ */
