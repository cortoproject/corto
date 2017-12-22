/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#ifndef CORTO_FMT
#define CORTO_FMT

struct corto_fmt_s {
    corto_string name;
    bool isBinary;

    /* Translate values to and from a contentType value */
    corto_word ___ (*fromValue)(corto_value *v);
    int16_t ___ (*toValue)(corto_value *v, corto_word content);

    /* Translate results to and from self-contained contentType values */
    corto_word ___ (*fromResult)(corto_result *o);
    int16_t ___ (*toResult)(corto_result* o, corto_word content);

    /* Translate objects to and from self-contained contentType values */
    corto_word ___ (*fromObject)(corto_object o);
    int16_t ___ (*toObject)(corto_object* o, corto_word content);

    /* Duplicate a contentType value */
    corto_word ___ (*copy)(corto_word content);

    /* Free a contentType value */
    void (*release)(corto_word content);
};

#endif
