#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

/** Contains a minimal value \p min and a related maximal value \p max. */
typedef struct {
   float min;
   float max;
} minmax_t;

/** Finds the minimal and maximal value in an array,
 * \return the minimal and maximal value in a minmax_t struct.
 * \todo unittest
 */
minmax_t findMinMax(const float data[], int size);

/** Calculates the average of all values in an input array \p data.
 * \return the average value.
 * \todo unittest
 */
float averageData(const float data[], int size);

/**
 * Resets all the values in the input array \p data so that the average
 * becomes equal to 0, and the values become between -1 and 1.
 *
 * \pre size >= 1
 * \param data input array
 * \param size number of data array elements
 * \todo unittest
 */
void meanNormalisation(float data[], int size);

/**
 * Converts all values in the input array \p data so that the minimum and
 * maximum value becomes equal to \p min and \p max. This conversion
 * function uses scaling (multiplication by A) and adds an offset (B) to
 * the input values:
 *
 * \f$ data[i] = A * data[i] + B \f$
 *
 * A and B are calculated by solving 2 equations using the actual min and
 * max values in the input data and the demanded \p min and \p max values
 * for the calculated result in \p data.
 *
 * \f$ min = A *  data\ actual\ min + B \f$
 *
 * \f$ max = A *  data\ actual\ max + B \f$
 *
 * \pre size >= 1 AND actual min < actual max AND \p min < \p max
 * \param data input array
 * \param size number of data array elements
 * \param min minimum value
 * \param max maximum value
 * \todo unittest
 */
void minmaxScaling(float data[], int size, float min, float max);

/**
 * Calculates  the in-product of two same sized arrays.
 * 
 * \param data1 array
 * \param data2 array
 * \param size array size
 * \return float in-product value
 * \todo implement
 * \todo unittest
 */
float inproduct(float data1[], float data2[], size_t size);

#endif // FUNCTIONS_H
