/*
 * HomogMatrix.hpp
 *
 *  Created on: 19-11-2010
 *      Author: mateusz
 */

#ifndef HOMOGMATRIX_HPP_
#define HOMOGMATRIX_HPP_

#include <boost/serialization/serialization.hpp>
#include <Eigen/Core>

namespace Types {

struct HomogMatrix
{

    Eigen::Matrix4f getElements(){
        return elements_;
    }

    void setElements(Eigen::Matrix4f elements){
        elements_ = elements;
    }

    double getElement(int x, int y){
        return elements_(x,y);
    }

    void setElement(int x, int y, double element){
        elements_(x,y) = element;
    }

private:

    //Eigen::Matrix<float,4,4,Eigen::DontAlign> elements_;
    Eigen::Matrix4f elements_;

    friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
        ar & elements_;
	}

};

} // namespace Types

#endif /* HOMOGMATRIX_HPP_ */
