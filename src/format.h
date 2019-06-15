/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <stdio.h>
#include <stdarg.h>
#include "handle.h"

void funnel_push_int(HANDLE*, long);
void funnel_push_int_row(HANDLE*, int, ...);

void funnel_push_uint(HANDLE*, unsigned long);
void funnel_push_uint_row(HANDLE*, int, ...);

void funnel_push_float(HANDLE*, double);
void funnel_push_float_row(HANDLE*, int, ...);