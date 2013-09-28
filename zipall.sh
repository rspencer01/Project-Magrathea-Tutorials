#!/bin/bash
rm *.zip
for i in */
do
  zip ${i%?} $i -r
done
