set +e

echo "umount /data"
umount /data
echo "force format /data"
mount -t fatfs -o forceformat /dev/data /data

echo "mount /sst"
mount -t littlefs /dev/sst /sst
if [ -d /sst/00000080 ]; then
    echo "clean sst"
    rm -r /sst/00000080
fi
