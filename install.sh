mkdir -p /usr/local/lib/corto/0.2
rc=$?; if [ $rc != 0 ]; then exit $rc; fi
cp -r ./build /usr/local/lib/corto/0.2
rc=$?; if [ $rc != 0 ]; then exit $rc; fi
export CORTO_TARGET=/usr/local
export CORTO_HOME=/usr/local
export CORTO_BUILD=/usr/local/lib/corto/0.2/build
export CORTO_VERSION=0.2
export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
rake silent=true verbose=false
rc=$?; if [ $rc != 0 ]; then exit $rc; fi
mv -f /usr/local/bin/corto /usr/local/bin/corto.0.2
ln -s /usr/local/bin/corto.0.2 /usr/local/bin/corto
rc=$?; if [ $rc != 0 ]; then exit $rc; fi
rake clean 2> /dev/null
rc=$?; if [ $rc != 0 ]; then exit $rc; fi
