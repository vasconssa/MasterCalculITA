#!/bin/bash

echo "<RCC>" > resources.qrc
echo '  <qresource prefix="/">' >> resources.qrc

for img in resources/images/*.png; do
    echo "      <file>$img</file>" >> resources.qrc
done

for img in resources/symbols/greek/*.png; do
    echo "      <file>$img</file>" >> resources.qrc
done

echo "  </qresource>" >> resources.qrc
echo "</RCC>" >> resources.qrc
