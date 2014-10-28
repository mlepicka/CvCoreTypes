/*
 * KeyPoints.hpp
 *
 *  Created on: 28-10-2014
 *      Author: mlaszkow
 */

#ifndef KEYPOINTS_HPP_
#define KEYPOINTS_HPP_

#include "Drawable.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

namespace Types {

class KeyPoints : public Drawable {
public:
    KeyPoints()
	{}

    KeyPoints(const Types::KeyPoints & _keypoints) {
        keypoints.insert(keypoints.end(), _keypoints.keypoints.begin(), _keypoints.keypoints.end());
	};

    KeyPoints(const std::vector<cv::KeyPoint> & _keypoints) {
        keypoints.insert(keypoints.end(), _keypoints.begin(), _keypoints.end());
	};

    virtual ~KeyPoints() {}

	virtual void draw(cv::Mat & image, cv::Scalar color, int offsetX = 0, int offsetY = 0) {
        cv::drawKeypoints(image, keypoints, image);
	}

	virtual Drawable * clone() {
        return new KeyPoints(*this);
	}

//private:
    std::vector<cv::KeyPoint> keypoints;
};

} //: namespace Types



#endif /* KEYPOINTS_HPP_ */
