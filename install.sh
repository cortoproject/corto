#!/bin/sh

install_cortex () {
    set -e

    VERSION="0.2.0"

    # Check supported OS
    UNAME=$(uname)
    if [ "$UNAME" != "Linux" -a "$UNAME" != "Darwin" ] ; then
        >&2 echo "Sorry, this OS is not supported yet."
        exit 1
    fi

    trap ">&2 echo Installation failed." EXIT

    TARBALL_URL="https://codeload.github.com/cortexlang/cortex/tar.gz/master"
    INSTALL_TMPDIR="$HOME/.cortex-install-tmp"
    rm -rf "$INSTALL_TMPDIR"
    mkdir "$INSTALL_TMPDIR"
    echo "Downloading Cortex source code"
    curl --progress-bar --fail "$TARBALL_URL" | tar -xzf - -C "$INSTALL_TMPDIR"
    # test -d "${INSTALL_TMPDIR}/cortex-master"
    # TODO change test
    # The files downloaded have the structure:
    # zipped file/
    # |-cortex <- executable that goes into /usr/local/bin
    # |-0.0.0/ <- directory named after version number
    #   |-packages/
    #   |-components/
    #   |-generators/

    # Remove previous installation
    echo "Removing any existing Cortex $VERSION installation."
    sudo rm -rf "/usr/local/lib/cortex/$VERSION"
    sudo mkdir "/usr/local/lib/cortex"
    sudo mkdir "/usr/local/lib/cortex/$VERSION"
    rm -rf "$HOME/.cortex/$VERSION"
    mkdir "$HOME/.cortex"
    mkdir "$HOME/.cortex/$VERSION"

    # TODO replace cortex-master with ultimate filename
    # Copy executable
    cp "$INSTALL_TMPDIR/cortex-master/cortex" "/usr/local/bin/cortex/$VERSION/"
    test -d "/usr/local/bin/cortex"
    cp "$INSTALL_TMPDIR/cortex-master/$VERSION" "$HOME/.cortex"
    rm -rf "${INSTALL_TMPDIR}"
    test -d "$HOME/.cortex/$VERSION/components"
    test -d "$HOME/.cortex/$VERSION/generators"
    test -d "$HOME/.cortex/$VERSION/packages"

    echo "The Cortex source code has been downloaded to \"~/.cortex\"."

    # Build
    cd "$HOME/.cortex"
    source configure
    rake
    test -x "$HOME/.cortex/bin/cortex"
    test -x "$HOME/.cortex/bin/cxgen"
    test -x "$HOME/.cortex/bin/cxsh"

    trap ">&2 echo Error building Cortex." EXIT

    if [ ! -d "/usr/local/bin" ] ; then
        sudo mkdir -m 755 "/usr/local" || true
        sudo mkdir -m 755 "/usr/local/bin" || true
    fi

    cp "$HOME/.cortex/bin/cortex" /usr/local/bin/
    cp "$HOME/.cortex/bin/cxgen" /usr/local/bin/
    cp "$HOME/.cortex/bin/cxsh" /usr/local/bin/

    echo "Cortex succesfully installed."
}

install_cortex
