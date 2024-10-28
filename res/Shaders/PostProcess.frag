
uniform sampler2D screen_texture;
uniform float scanline_count = 60.0;

float redOffset   =  0.002;
float greenOffset =  0.0009;
float blueOffset  = -0.0009;

vec2 uv_curve(vec2 uv)
{
	uv = (uv - 0.5) * 2.0;
	
	//You can modify the numbers and try different values
	uv.x *= 1.0 + pow(abs(uv.y) / 5.0, 2.0);
	uv.y *= 1.0 + pow(abs(uv.x) / 5.0, 2.0);
	
	//The scale part (you can delete it when you want)
	uv /= 1.2;
	
	uv = (uv/2.0) + 0.5;
	return uv;
}


void main()
{	
	float PI = 3.14159;
	
	//You can modify the *3.0, *-3.0 for a bigger or smaller 
	float r = texture(screen_texture, uv_curve(gl_TexCoord[0].xy) + redOffset).r;
	float g = texture(screen_texture, uv_curve(gl_TexCoord[0].xy) + greenOffset).g;
	float b = texture(screen_texture, uv_curve(gl_TexCoord[0].xy) + blueOffset).b;
	
	
	//If you dont want scanlines you can just delete this part
	float s = sin(uv_curve(gl_TexCoord[0].xy).y * scanline_count * PI * 2.0);
	s = (s * 0.5 + 0.5) * 0.1 + 0.3;
	vec4 scan_line = vec4(vec3(pow(s, 0.25)), 1.0);
	
	
	gl_FragColor = vec4(r, g, b, 1.0) * scan_line;
}