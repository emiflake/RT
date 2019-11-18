{
	"camera": {
		"fov": 70,
		"origin": [3, 4.50, 0],
		"rotation": [0, 0, 0]
	},
	"objects": [
		{
			"type": "square",
			"origin": [-5, 5, 12],
			"side_b": [0, 0, 5],
			"side_a": [5, 3, 0],
			"emission": [555, 555, 555],
			"color": [255, 255, 255],
			"blurry": 1
		},
		{
			"type": "sphere",
			"origin": [0, 1.5, 14],
			"axis": [0.5, 0, 0.866],
			"radius": 1,
			"emission": [0, 0, 0],
			"color": [255, 0, 0],
			"blurry": 1,
			"reflective": 0,
			"refraction": 1.5,
			"transparent": 0
		},
		{
			"type": "sphere",
			"origin": [0, 1.5, 12],
			"axis": [0.5, 0, 0.866],
			"radius": 1,
			"emission": [0, 0, 0],
			"color": [255, 255, 255],
			"blurry": 0,
			"reflective": 1,
			"refraction": 3,
			"transparent": 1
		},
		{
			"type": "plane",
			"origin": [0, 0, 0],
			"normal": [0, 1, 0],
			"color": [255, 255, 255],
			"blurry": 1,
			"reflective": 0
		}
	]
}
