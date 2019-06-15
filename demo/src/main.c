/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../src/funnel.h"

int main(int argc, char** argv)
{
    printf("hello world\n");

    FUNNEL demo = funnel_open("test.csv");
    if (demo == NULL)
    {
        printf("cannot open funnel\n");
        return 1;
    }

    int i;
    int j;
    for (i = 0; i < 1024; ++i)
    {
        for (j = 0; j < 1024; ++j)
        {
            funnel_push_int(demo, i * j);
        }
        funnel_write(demo, "\n");
    }

    funnel_close(demo);

    return 0;
}