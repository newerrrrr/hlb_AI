#include "FuzzySet_Triangle.h"
#include "common/misc/UtilsEx.h"


float FuzzySet_Triangle::calculateDOM(float val)const
{
    //test for the case where the triangle's left or right offsets are zero
    //(to prevent divide by zero errors below)
    if ( (isEqual(m_dRightOffset, 0.0) && (isEqual(m_dPeakPoint, val))) ||
                (isEqual(m_dLeftOffset, 0.0) && (isEqual(m_dPeakPoint, val))) )
    {
        return 1.0;
    }

    //find DOM if left of center
    if ( (val <= m_dPeakPoint) && (val >= (m_dPeakPoint - m_dLeftOffset)) )
    {
        float grad = 1.0 / m_dLeftOffset;
        return grad * (val - (m_dPeakPoint - m_dLeftOffset));
    }
    //find DOM if right of center
    else if ( (val > m_dPeakPoint) && (val < (m_dPeakPoint + m_dRightOffset)) )
    {
        float grad = 1.0 / -m_dRightOffset;
        return grad * (val - m_dPeakPoint) + 1.0;
    }
    //out of range of this FLV, return zero
    else
    {
        return 0.0;
    }
}