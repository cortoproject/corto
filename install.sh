#!/bin/sh

set -e

# Check supported OS
UNAME=$(uname)
if [ "$UNAME" != "Linux" -a "$UNAME" != "Darwin" ] ; then
    >&2 echo "Sorry, this OS is not supported yet."
    exit 1
fi

# Check rails
command -v rake >/dev/null 2>&1 || { echo >&2 "I require rake but it's not installed.  Aborting."; exit 1; }

trap ">&2 echo Installation failed." EXIT

if [ -e "$HOME/.cortex" ]; then
    echo "Removing your existing Cortex installation."
    rm -rf "$HOME/.cortex"
fi

TARBALL_URL="https://codeload.github.com/cortexlang/cortex/tar.gz/master"
INSTALL_TMPDIR="$HOME/.cortex-install-tmp"

rm -rf "$INSTALL_TMPDIR"
mkdir "$INSTALL_TMPDIR"
echo "Downloading Cortex source code"
curl --progress-bar --fail "$TARBALL_URL" | tar -xzf - -C "$INSTALL_TMPDIR"
test -d "${INSTALL_TMPDIR}/cortex-master"
rm -rf "$HOME/.cortex"
mkdir "$HOME/.cortex/"
# TODO does this fail if there are spaces in the name?
mv $INSTALL_TMPDIR/cortex-master/* "$HOME/.cortex/"
rm -rf "${INSTALL_TMPDIR}"
test -d "$HOME/.cortex"

echo "The Cortex source code has been downloaded to \"~/.cortex\"."

# Build
cd "$HOME/.cortex"
source configure
rake
test -x "$HOME/.cortex/bin/cortex"
test -x "$HOME/.cortex/bin/cxgen"
test -x "$HOME/.cortex/bin/cxsh"

trap ">&2 echo Error building Cortex." EXIT

if [ ! -d "usr/local/bin" ] ; then
    sudo mkdir -m 755 "usr/local" || true
    sudo mkdir -m 755 "usr/local/bin" || true
fi

cp "$HOME/.cortex/bin/cortex" usr/local/bin/
cp "$HOME/.cortex/bin/cxgen" usr/local/bin/
cp "$HOME/.cortex/bin/cxsh" usr/local/bin/

echo "Cortex succesfully installed."

}

run_it
