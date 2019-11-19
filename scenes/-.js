{
	"camera": {
		"fov": 70,
		"origin": [0, 4.50, -3],
		"rotation": [0, 0, 0]
	},
	"objects": [
		{
			"type": "square",
			"origin": [-800, 400, 0],
			"side_b": [0, 0, 1600],
			"side_a": [1600, 0, 0],
			"emission": [255, 255, 255],
			"color": [255, 255, 255],
			"blurry": 1
		},
		{
			"type": "square",
			"origin": [0, 1.5, 1],
			"side_b": [0, 1.5, 0],
			"side_a": [1.5, 0, 1],
			"emission": [0, 0, 0],
			"color": [255, 255, 255],
			"blurry": 0,
			"reflective": 1,
			"refraction": 1.5,
			"transparent": 1
		},
		{
			"type": "disk",
			"origin": [0, 1, 3],
			"normal": [0, 1, 0],
			"inner_radius": 0.5,
			"outer_radius": 1,
			"emission": [0, 0, 0],
			"color": [127, 255, 0],
			"blurry": 1
		},
		{
			"type": "tetrahedron",
			"a_pos": [-4, 3.5, 6],
			"b_pos": [-4, 1, 4],
			"c_pos": [-2, 1, 5],
			"d_pos": [-3, 1, 7],
			"emission": [0, 0, 0],
			"color": [255, 255, 0],
			"blurry": 1
		},
		{
			"type": "cube",
			"origin": [-2, 1, 5],
			"axis_vert": [0.5, 1, 0.866],
			"size": [1, 1, 1],
			"emission": [0, 0, 0],
			"color": [255, 0, 255]
		},
		{
			"type": "cone",
			"origin": [2, 3, 5],
			"axis": [0.866, 0, 0.5],
			"angle_deg": 30,
			"pos_height": 1,
			"neg_height": -1,
			"emission": [0, 0, 0],
			"color": [0, 255, 0],
			"blurry": 1
		},
		{
			"type": "pyramid",
			"a_pos": [-1, 1, 6],
			"b_pos": [1, 1, 6],
			"c_pos": [1, 3, 6],
			"d_pos": [-1, 3, 6],
			"origin": [0, 2, 4],
			"emission": [0, 0, 0],
			"color": [0, 255, 127],
			"blurry": 1
		},
		{
			"type": "triangle",
			"a_pos": [1, 0, 5],
			"b_pos": [2, 2, 5],
			"c_pos": [3, 0, 5],
			"a_normal": [-1, -1, -1],
			"b_normal": [0, 1, 1],
			"c_normal": [1, -1, -1],
			"emission": [0, 0, 0],
			"color": [0, 127, 255],
			"blurry": 1
		},
		{
			"type": "sphere",
			"origin": [-1, 2, 4],
			"axis": [0.5, 0, 0.866],
			"radius": 1,
			"emission": [0, 0, 0],
			"color": [255, 255, 0],
			"blurry": 0,
			"reflective": 1,
			"refraction": 1.5,
			"transparent": 1
		},
		{
			"type": "cylinder",
			"origin": [-4, 3, 10],
			"axis": [0.5, 0, -0.866],
			"radius": 0.5,
			"pos_height": 4,
			"neg_height": -4,
			"emission": [0, 0, 0],
			"color": [0, 0, 255],
			"blurry": 1
		},
		{
			"type": "plane",
			"origin": [0, 0, 0],
			"normal": [0, 1, 0],
			"color": [255, 255, 255],
			"blurry": 0.5,
			"reflective": 0.5
		}
	]
}