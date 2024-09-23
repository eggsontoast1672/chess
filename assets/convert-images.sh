if [ ! -d svg ]; then
  echo "This script is meant to be run from the assets directory"
  echo "Exiting now..."
  exit 1
fi

if [ ! -d png ]; then
  mkdir png
fi

for image in svg/*.svg; do
  # Extract the name of the file, sans the path and extension.
  name="$(basename "${image}" .svg)"
  magick -background none -size 256x256 -verbose \
    "${image}" "png/${name}.png"
done
