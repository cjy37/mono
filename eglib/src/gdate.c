/*
 * Date and time utility functions.
 *
 * Author:
 *   Gonzalo Paniagua Javier (gonzalo@novell.com
 *
 * (C) 2006 Novell, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <stdio.h>
#include <glib.h>

#ifdef G_OS_WIN32
#include <winsock2.h>
#else
#include <sys/time.h>
#endif

void
g_get_current_time (GTimeVal *result)
{
#ifdef G_OS_WIN32
	long int l = GetTickCount();

	g_return_if_fail (result != NULL);

	result->tv_sec = l / 1000;
	result->tv_usec = (l % 1000) * 1000;
#else
	struct timeval tv;

	g_return_if_fail (result != NULL);
	gettimeofday (&tv, NULL);
	result->tv_sec = tv.tv_sec;
	result->tv_usec = tv.tv_usec;
#endif
}