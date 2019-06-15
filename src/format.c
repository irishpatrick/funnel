/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "format.h"
#include <string.h>

#define SCRATCH_BUFFER_SIZE 30

void funnel_push_int(HANDLE* handle, long value)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;
    sprintf(tmp, "%ld,", value);
    funnel_write(handle, tmp);
}

void funnel_push_int_row(HANDLE* handle, int num, ...)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;

    va_list list;
    int i;

    va_start(list, num);
    for (i = 0; i < num; ++i)
    {
        long value = va_arg(list, long);
        sprintf(tmp, "%ld,", value);
        funnel_write(handle, tmp);
        tmp[0] = '\0';
    }

    funnel_write(handle, "\n");

    va_end(list);
}

void funnel_push_uint(HANDLE* handle, unsigned long value)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;
    sprintf(tmp, "%lu,", value);
    funnel_write(handle, tmp);
}

void funnel_push_uint_row(HANDLE* handle, int num, ...)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;

    va_list list;
    int i;

    va_start(list, num);
    for (i = 0; i < num; ++i)
    {
        unsigned long value = va_arg(list, unsigned long);
        sprintf(tmp, "%lu,", value);
        funnel_write(handle, tmp);
        tmp[0] = '\0';
    }

    funnel_write(handle, "\n");

    va_end(list);
}

void funnel_push_float(HANDLE* handle, double value)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;
    sprintf(tmp, "%lf,", value);
    funnel_write(handle, tmp);
}

void funnel_push_float_row(HANDLE* handle, int num, ...)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;

    va_list list;
    int i;

    va_start(list, num);
    for (i = 0; i < num; ++i)
    {
        double value = va_arg(list, double);
        sprintf(tmp, "%f,", value);
        funnel_write(handle, tmp);
        tmp[0] = '\0';
    }

    funnel_write(handle, "\n");

    va_end(list);
}
