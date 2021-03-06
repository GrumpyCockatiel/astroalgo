#include "astroalgo.h"
#include "astromath.h"

/* C Headers */
#include <math.h>

/*******************************************************************************
*	NAME:
*		SimpleIllumination
*		
*	PURPOSE:
*		Calculate the percent illumination of the moon ( 0 <= k <= 1 )
*		on the given input Julian Day
*		
*	REFERENCES:
*		Meeus, Jean. "Astronomical Algorithms, 1st ed." Willmann-Bell. Inc. 1991.
*			pp. 315
*			
*	INPUT ARGUMENTS:
*		inJulian (double)
*			fractional Julian Day to calculate percent illumination of the moon's disc on
*	
*	OUTPUT ARGUMENTS:
*		none
*	 
*	RETURNED VALUE:
*	 	illuminated fraction of moon's disc
*	 
*	GLOBALS USED:
*	 	none
*	 
*	FUNCTIONS CALLED:
*	 	SinD, CosD, Revolution, atan2
*	 
*	DATE/PROGRAMMER/NOTE:
*	 	07-31-2001	Todd A. Guillory	created
*
********************************************************************************/
double simple_illumination( double inJulian )
{
	double	k;		/* illuminated fraction of moon's disc */
	double	T;		/* Julian Centuries */
	double	i;		/* phase angle of the moon */
	double	D;		/* mean elogation of the moon */
	double	M;		/* sun's mean anomaly */
	double	Mprime;	/* moon's mean anomaly */

	/* pg. 131 */
	T =  ( inJulian - 2451545.0) / 36525.0;
  
	D = 297.8502042 + (445267.1115168 * T) 
                    - (0.0016300 * T * T) 
                    + ((T * T * T)/545868) 
                    - ((T * T * T * T)/113065000);
    
	M = 357.5291092 + (35999.0502909 * T) 
                    - (0.0001536 * T * T) 
                    + ((T * T * T)/24490000);
  
	Mprime = 134.9634114 + (477198.8676313 * T) 
                         + (0.0089970 * T * T) 
                         + ((T * T * T)/69699) 
                         - ((T * T * T * T)/14712000);
  
	D = fmod(D, 360.0);
	M = fmod(M, 360.0);
	Mprime = fmod(Mprime, 360.0);
  
 	M = kDegRad * M;
	Mprime = kDegRad * Mprime;
  
	i = 180 - D - (6.289 * sin(Mprime))
                + (2.100 * sin(M))
                - (1.274 * sin(2 * kDegRad * D - Mprime))
                - (0.658 * sin(2 * kDegRad * D))
                - (0.214 * sin(2 * Mprime))
                - (0.110 * sin(kDegRad * D));

	k = (1 + CosD(i)) / 2;

	return k;
}
