/*
 * HomogMatrix.hpp
 *
 *  Created on: 26.05.2015
 *  Author: tkornuta
 */

#ifndef HOMOGMATRIX_HPP_
#define HOMOGMATRIX_HPP_

#include <Eigen/Core>
#include <Eigen/Geometry> 
#include <opencv2/core/core.hpp>

namespace Types {

/// Base HomogMatrix type.
typedef Eigen::Transform< double, 3, Eigen::Affine > HomogMatrixBaseType;


/// Class representing homogenous matrix.
struct HomogMatrix : public HomogMatrixBaseType
{
	/// Base constructor - creates an identity matrix.
	HomogMatrix() : HomogMatrixBaseType ( HomogMatrixBaseType::Identity ())
	{
	}

/*	/// Constructor copying  - creates an identity matrix.
	HomogMatrix() ( const HomogMatrix & hm_) : HomogMatrix( hm_)
	{
		
	}*/

	/// Constructor casting the 4x4 OpenCv matrix Matx44d to HomogMatrix (Eigen matrix Matrix4d).
	HomogMatrix(cv::Matx44d mat_) {
	
		// Check proper sizes of cv::mat  -- not required as strong typing is used.
		//assert ( (mat_.rows() == 4) && (mat_.cols() == 4)) || 16x1 || 1x16

		// Copy values to cv::mat.
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) 
				(*this)(i,j) = mat_(i,j);
	}


	/// Method casts the HomogMatrix (Eigen matrix Matrix4d) to 4x4 OpenCv matrix Matx44d.
	operator cv::Matx44d const()
	{
		cv::Matx44d mat;
		// Copy values to cv::mat.
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) 
				mat(i,j) = (*this)(i,j);
		return mat;
	}



	/// Redirect the output stream.
	friend ostream & operator<< (ostream &out_, const HomogMatrix &hm_) {
   		return out_ << hm_.matrix();
	}

};




} // namespace Types

#endif /* HOMOGMATRIX_HPP_ */
