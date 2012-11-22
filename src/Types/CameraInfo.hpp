/*
 * CameraInfo.hpp
 *
 *  Created on: 22-11-2012
 *      Author: mstefanc
 */

#ifndef CAMERAINFO_HPP_
#define CAMERAINFO_HPP_

namespace Types {

class CameraInfo {
public:
	CameraInfo(int w, int h, float cx, float cy, float fx, float fy) :
		m_width(w), m_height(h),
		m_cx(cx), m_cy(cy), m_fx(fx), m_fy(fy)
	{}

	float cx() const {
		return m_cx;
	}

	void setCx(float cx) {
		m_cx = cx;
	}

	float cy() const {
		return m_cy;
	}

	void setCy(float cy) {
		m_cy = cy;
	}

	float fx() const {
		return m_fx;
	}

	void setFx(float fx) {
		m_fx = fx;
	}

	float fy() const {
		return m_fy;
	}

	void setFy(float fy) {
		m_fy = fy;
	}

	int height() const {
		return m_height;
	}

	void setHeight(int height) {
		m_height = height;
	}

	int width() const {
		return m_width;
	}

	void setWidth(int width) {
		m_width = width;
	}

private:
	int m_width;
	int m_height;
	float m_cx, m_cy;
	float m_fx, m_fy;
};

}

#endif /* CAMERAINFO_HPP_ */
