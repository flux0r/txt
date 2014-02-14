/** \file
        
        The public interface to arrays of Unicode code points.

*/
#include <stdbool.h>
#include "util.h"

/** An array type. */
typedef struct Array {
        Cp      *data;          /**< Unicode code points. */
        Len     len;            /**< Length in ``Cp''s. */
} Array;

/** Make a new array.
 * 
 * \param dest  The destination.
 * \param data  The data.
 * \param l     The length in elements.
 *
 * \return      The destination.
 *
 */
Array *
arr_mk(Array *arr, Cp *data, Len l);


/** Copy an array by copying the actual data; i.e., don't just copy the
 * pointer.
 *
 * \param dest          The destination.
 * \param destix        The destination offset.
 * \param src           The source.
 * \param srcix         The source offset.
 * \param l             The length.
 * 
 * \return              The destination.
 *
 */
Array *
arr_copy(Array *dest, Off destix, Array *src, Off srcix, Len l);


/** An empty, uninitialized Array.
 *
 * \param dest  The destination pointer.
 *
 * \return      The destination pointer.
 *
 */
Array *
arr_empty(Array *dest);


/** Compare sections of two Arrays for equality.
 *
 * \param xs    The first array pointer.
 * \param xsix  The offset of the start of the region in the first array.
 * \param ys    The second array pointer.
 * \param ysix  The offset for the second array.
 * \param l     The length of the comparison region.
 *
 * \return      A bool indicating whether the regions are equal.
 *
 */
bool
arr_equal(Array *xs, Off xsix, Array *ys, Off ysix, Len l);
