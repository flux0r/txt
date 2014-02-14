/** \file
        
        The implementation of arrays of Unicode code points.

*/
#include <stdio.h>
#include <string.h>
#include "array.h"

/** Make a new Array.
 * 
 * \param dest  A pointer to the destination struct.
 * \param data  A pointer to the start of the data.
 * \param l     The length of the Array in elements.
 *
 * \return      The destination pointer.
 *
 */
Array *
arr_mk(Array *dest, Cp *data, Len l)
{
        *dest = (Array){.data=data, .len=l};
        return dest;
}


/** Copy an Array by copying the actual data; i.e., don't just copy the
 * pointer.
 *
 * \param dest          A pointer to the destination location.
 * \param destix        The offset from dest indicating the start of the
 *                      data you're copying.
 * \param src           A pointer to the source to copy from.
 * \param srcix         The offset from src indicating the start of the
 *                      region to which you're copying.
 * \param l             The length in code points of the region you're
 *                      copying.
 * 
 * \return              The destination pointer.
 *
 */
Array *
arr_copy(Array *dest, Off destix, Array *src, Off srcix, Len l)
{
        Array *r = memcpy(&dest + destix, &src + srcix, l);
        return r;
}


/** Create a new uninitialized Array.
 * 
 * \param dest  The destination pointer.
 * \param l     The length of the new Array.
 *
 * \return      The destination pointer
 *
 */
Array *
arr_new(Array *dest, Len l)
{
        void *empty = NULL;
        return arr_mk(dest, empty, 0);
}


/** An empty, uninitialized Array.
 *
 * \param dest  The destination pointer.
 *
 * \return      The destination pointer.
 *
 */
Array *
arr_empty(Array * dest)
{
        return arr_new(dest, 0);
}


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
arr_equal(Array *xs, Off xsix, Array *ys, Off ysix, Len l)
{
        int r = memcmp(&xs + xsix, &ys + ysix, l);
        return r == 0;
}

int main() {};
