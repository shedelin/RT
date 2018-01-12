# scene sujet by Miaou

camera
position	0 5 -15 
look		0 1 0
direction	0 1 0

# spots

spot
position	10 5 -20
color		255 255 255

spot
position	-10 5 -20
color		255 255 255

spot
position	0 1 -5
color		255 255 255

# objets
object
type
sphere
size 			1
position 		3 1 0
rotation_xyz	250 40 0
color			0 255 0
material
mat1

object
type
sphere
size 			1
position 		-3 1 0
rotation_xyz	250 40 0
color			255 0 0
material
mat1

object
type
cylinder
size			40
position		-1 1 0
color			253 108 158
rotation_xyz	0 0 135
material
mat1

object
type
cone
angle			50
position		1 1 0
color			255 255 0
rotation_xyz	45 90 0
material
mat1

object
type
plane
direction		0 -1 0
position		0 0 5 
color			0 0 255
rotation_xyz	90 0 0
material
mat2

object
type
plane
direction		0 -1 0
position		0 0 0 
color			150 150 150
rotation_xyz	0 0 0
material
mat1
