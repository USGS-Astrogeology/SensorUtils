#include "SensorUtils.h"

#include "math.h" 

#include <vector>

#include <armadillo>

using namespace std;


 /**
   * Computes and returns phase angle, in radians, given the positions of the
   * observer and illuminator.
   *
   * Phase Angle: The angle between the vector from the intersection point to
   * the observer (usually the spacecraft) and the vector from the intersection
   * point to the illuminator (usually the sun).
   *
   * @param observerBodyFixedPosition  Three dimensional position of the observer,
   *                                   in the coordinate system of the target body.
   * @param illuminatorBodyFixedPosition Three dimensional position for the illuminator,
   *                                     in the body-fixed coordinate system.
   * @param surfaceIntersection Three dimensional position for the ground point,
   *                                     in the body-fixed coordinate system.
   * @return @b double Phase angle, in radians (was degrees).
   */

double PhaseAngle(const std::vector<double> &observerBodyFixedPosition,
                                const std::vector<double> &illuminatorBodyFixedPosition,
				const std::vector<double> &surfaceIntersection) {

    //convert the vector to an arma::vec
    arma::vec observer = arma::zeros<arma::vec>(3);
    observer = arma::conv_to<arma::vec>::from(observerBodyFixedPosition);

    //convert the illuminatorBodyFixedPosition vector to an arma::vec
    arma::vec illuminator = arma::zeros<arma::vec>(3);
    illuminator = arma::conv_to<arma::vec>::from(illuminatorBodyFixedPosition);

    //convert the surfaceIntersection vector to an arma::vec
    arma::vec pB = arma::zeros<arma::vec>(3);
    pB = arma::conv_to<arma::vec>::from(surfaceIntersection);    

    // Get vector from surface point to observer and normalise it 
    arma::vec psB = arma::zeros<arma::vec>(3);
    arma::vec upsB = arma::zeros<arma::vec>(3);
    arma::vec dist = arma::zeros<arma::vec>(3);
    psB = observer - pB; 
    upsB = arma::normalise(psB);

    // Get vector from surface point to sun and normalise it
    arma::vec puB = arma::zeros<arma::vec>(3);
    arma::vec upuB = arma::zeros<arma::vec>(3);
    puB = illuminator - pB; 
    upuB = arma::normalise(puB);

    double dotpr=arma::dot(upsB,upuB);

    // How can these lines be tested???
    if(dotpr > 1.0) return 0.0; 
    if(dotpr < -1.0) return M_PI;
   
    return acos(dotpr);

}

