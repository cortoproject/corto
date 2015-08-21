#!/bin/sh

install_cortex_fail() {
    >&2 echo "Installation failed."
    rm -rf "$INSTALL_TMPDIR"
}

install_cortex () {
    set -e
    set -u
    VERSION="0.2.0"

    # Check supported OS
    UNAME=$(uname)
    if [ "$UNAME" != "Linux" -a "$UNAME" != "Darwin" ] ; then
        >&2 echo "Sorry, this OS is not supported yet."
        exit 1
    fi
    ARCHITECTURE=$(uname -p)
    if [ "$UNAME" = "Darwin" ] ; then
        if [ "i386" != "$(uname -p)" -o "1" != "$(sysctl -n hw.cpu64bit_capable 2>/dev/null || echo 0)" ] ; then
          >&2 echo "Only 64-bit Intel processors are supported at this time."
          exit 1
        fi
    fi

    trap install_cortex_fail EXIT

    FILENAME="cortex$VERSION"
    TARBALL_URL="https://s3.amazonaws.com/cortexbinaries/$UNAME/$ARCHITECTURE/$FILENAME.tar.gz"
    INSTALL_TMPDIR="$HOME/.cortex-install-tmp"
    rm -rf "$INSTALL_TMPDIR"
    mkdir "$INSTALL_TMPDIR"
    echo "Downloading Cortex source code from $TARBALL_URL."
    curl --progress-bar --fail "$TARBALL_URL" | tar -xzf - -C "$INSTALL_TMPDIR"
    test -d "${INSTALL_TMPDIR}/bin"
    test -d "${INSTALL_TMPDIR}/$VERSION"
    # The files downloaded have the structure:
    # zipped file/
    # |-cortex <- executable that goes into /usr/local/bin
    # |-0.0.0/ <- directory named after version number
    #   |-packages/
    #   |-components/
    #   |-generators/

    if [ ! -d "/usr/local/bin" ] ; then
        sudo mkdir -m 755 "/usr/local" || true
        sudo mkdir -m 755 "/usr/local/bin" || true
    fi

    echo "Removing your existing Cortex $VERSION installation."
    sudo rm -rf "/usr/local/bin/cortex/$VERSION"
    sudo rm -rf "/usr/local/lib/cortex/$VERSION"
    rm -rf "$HOME/.cortex/$VERSION"
    sudo mkdir -p "/usr/local/bin/cortex/$VERSION"
    sudo mkdir -p "/usr/local/lib/cortex/$VERSION"
    mkdir -p "$HOME/.cortex"

    echo "Copying files."
    # Copy basic files
    sudo cp "$INSTALL_TMPDIR/bin/cortex" "/usr/local/bin/cortex.$VERSION"
    sudo cp "$INSTALL_TMPDIR/bin/libcortex.so" "/usr/local/lib/libcortex.so.$VERSION"
    # Copy interface, generator, packages
    sudo cp -R "$INSTALL_TMPDIR/$VERSION" "/usr/local/lib/cortex/" > /dev/null
    test -x "/usr/local/bin/cortex/$VERSION/cortex"
    test -d "/usr/local/lib/cortex/$VERSION/interface"
    test -d "/usr/local/lib/cortex/$VERSION/generator"
    test -d "/usr/local/lib/cortex/$VERSION/packages"
    rm -rf "${INSTALL_TMPDIR}"
    echo "Cortex succesfully installed."
    trap - EXIT
}

install_cortex
