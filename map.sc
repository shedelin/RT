#	scene de test pour RT By KeKE


		  camera
position	0 3 -20
look		0 3 0
direction	0 1 0



# positionnement des spots
		  spot
position	0 6 -3
color		255 0 255
		  spot
position	0 1 5
color		0 255 0
		  spot
position	5 5 5
color		255 255 255



# positionnement des objets
		  object
type
	sphere
	size	1
position		0 0 0
color			255 255 255
material
	mat3
rotation_xyz	350 50 0

		  object
type
	ellipsoid
	sizes_xyz	5 3 1
position		4 -2 0
color			0 0 255
rotation_xyz	180 0 0
material
	mat4

		  object
type
	sphere
	size	1
position		0 4 0
color			255 255 0
rotation_xyz	0 0 0
material
	mat5

		  object
type
	sphere
	size	1
position		0 0 6
color			255 255 0
rotation_xyz	0 0 0
material
	mat3

		  object
type
	plane
	direction	0 -1 0
position		0 -3 0
color			255 255 255
rotation_xyz	0 0 0
material
	mat4

		  object
type
	plane
	direction	0 1 0
position		0 7 0
color			255 255 255
rotation_xyz	0 0 0
material
	mat4

		  object
type
	plane
	direction	0 0 1
position		0 -1 20
color			255 255 255
rotation_xyz	0 0 0
material
	mat4

		  object
type
	plane
	direction	0 0 -1
position		0 7 -20
color			255 255 255
rotation_xyz	0 0 0
material
	mat4

		  object
type
	plane
	direction	1 0 0
position		10 -5 0
color			255 255 255
rotation_xyz	0 0 0
material
	mat4

		  object
type
	plane
	direction	-1 0 0
position		-10 -5 0
color			255 255 255
rotation_xyz	0 0 0
material
	mat4

		  object
type
	cylinder
	size		20
position		0 100 0
color			0 255 0
rotation_xyz	0 0 0
material
	mat3

		  object
type
	cone
	angle		50
position		-5 2 3
color			140 255 100
rotation_xyz	90 0 120
material
	mat4
