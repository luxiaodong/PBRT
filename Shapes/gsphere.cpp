#include "gsphere.h"

GSphere::GSphere(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float radius, float zMin, float zMax, float phiMax)
        :GShape(objectToWorld, worldToObject, reverseOrientation),
          m_radius(radius),
          m_zMin( GMath::clamp(-radius, radius, qMin(zMin, zMax)) ),
          m_zMax( GMath::clamp(-radius, radius, qMax(zMin, zMax)) ),
          m_thetaMin( qAcos( GMath::clamp(-1,1, qMin(zMin, zMax)/radius)) ),
          m_thetaMax( qAcos( GMath::clamp(-1,1, qMax(zMin, zMax)/radius)) ),
          m_phiMax( GMath::clamp(0, 360, phiMax) )
{

}
