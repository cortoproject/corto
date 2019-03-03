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

 /** @file
  * @section security Security
  * @brief Secure data in the object store.
  */

#ifndef CORTO_SECURITY_H
#define CORTO_SECURITY_H

#ifdef __cplusplus
extern "C" {
#endif

/** Login to a new session.
 * A login creates a new session, identified by a session token. After logging
 * in the session is not yet active. To activate a session, pass the session
 * token to the corto_set_session function.
 *
 * A typical example of a session token can be an API key.
 *
 * @param username The username of the user logging in.
 * @param password The password of the user logging in.
 * @return The session token if login is valid. NULL if the login failed.
 * @see corto_logout
 */
CORTO_EXPORT
const char *corto_login(
    const char *username,
    const char *password);

/** Logout of a session.
 * After logging out, a session token is no longer guaranteed to authenticate
 * a user.
 *
 * @param token An existing session token.
 * @see corto_login
 */
CORTO_EXPORT
void corto_logout(
    const char *token);

/** Set active session.
 * This sets the global session variable for the corto process. All
 * authorization requests will use the specified session token.
 *
 * Certain corto mechanisms (like subscribers) are associated with their own
 * session token that they obtained at creation time. This allows a corto
 * process to be multi-tenant.
 *
 * @param token An existing session token.
 * @return The previous session token.
 * @see corto_login
 */
CORTO_EXPORT
const char *corto_set_session(
    const char *token);

/** Get active session.
 * This gets the global session variable for the corto process.
 *
 * @return The current session token.
 * @see corto_set_session
 */
CORTO_EXPORT
const char *corto_get_session(void);

/** Authorize the current session for an action on an object.
 *
 * @param o The object for which to authorize.
 * @param action The action to authorize.
 * @return true when authorized, false when not authorized.
 * @see corto_set_session
 */
CORTO_EXPORT
bool corto_authorize(
    corto_object object,
    corto_secure_actionKind action);

/** Authorize the current session for an action on an object identifier.
 *
 * @param id The object identifier for which to authorize.
 * @param action The action to authorize.
 * @return true when authorized, false when not authorized.
 * @see corto_set_session
 */
CORTO_EXPORT
bool corto_authorize_id(
    const char *id,
    corto_secure_actionKind access);

/** Register a new user.
 *
 * @param userId The user identifier.
 * @param password The password for the user.
 * @param group The group of the user.
 * @param home The home scope of the user.
 * @return 0 when success, non-zero when failed.
 * @see ut_userdel corto_login corto_logout
 */
CORTO_EXPORT
int16_t ut_useradd(
    const char *userId,
    const char *password,
    const char *group,
    const char *home);

/** Unregister a user.
 *
 * @param userId The user identifier.
 * @return 0 when success, non-zero when failed.
 * @see ut_useradd corto_login corto_logout
 */
CORTO_EXPORT
int16_t ut_userdel(
    const char *userId);

/** Test if process is secured.
 * This function provides a quick check to see if the process is secured. If the
 * process is not secured, security-related functions will fail, and all
 * requests for authorization are disabled.
 *
 * @return true when secured, false when not secured.
 */
CORTO_EXPORT
bool corto_secured(void);

#ifdef __cplusplus
}
#endif

#endif
