# scene ovni by Miaou

camera
position	0 25 80 
look		0 1 0
direction	0 1 0

# spots

spot
position	-15 15 0
color		255 255 255

spot
position	15 15 0
color		255 255 255

# objets
object
type
sphere
size 			5
position 		0 3 0
rotation_xyz	250 40 0
color			150 150 150
material
mat10

object
type
ellipsoid
sizes_xyz		1 15 15
position		0 3 0
rotation_xyz	0 0 90
color			150 150 150
material
mat10

object
type
plane
direction		0 -1 0
position		0 -20 0 
color			255 0 0
rotation_xyz	0 0 0
material
mat2

object
type
plane
direction		0 -1 0
position		0 0 -60 
color			0 0 255
rotation_xyz	90 0 0
material
mat2

object
type
sphere
size 			2
position 		-10 3 0
rotation_xyz	250 40 0
color			255 255 255
material
mat3

object
type
sphere
size 			2
position 		10 3 0
rotation_xyz	250 40 0
color			255 255 255
material
mat3

object
type
sphere
size 			2
position 		0 3 10
rotation_xyz	250 40 0
color			255 255 255
material
mat3

object
type
sphere
size 			2
position 		0 3 -10
rotation_xyz	250 40 0
color			255 255 255
material
mat3
