#type vertex
#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexIndex;
layout(location = 4) in float a_TillingFactor;

uniform mat4 u_ViewProjectionMatrix;

out vec3 v_Position;
out vec2 v_TexCoord;
out vec4 v_Color;
out float v_TexIndex;
out float v_TillingFactor;

void main()
{
    v_Color = a_Color;
	v_TexCoord = a_TexCoord;
	v_Position = a_Position;
	v_TexIndex = a_TexIndex;
	v_TillingFactor = a_TillingFactor;
	gl_Position = u_ViewProjectionMatrix * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;
//in vec3 v_Position;
in vec2 v_TexCoord;
in vec4 v_Color;
in float v_TexIndex;
in float v_TillingFactor;

uniform sampler2D u_Texture[32];

void main()
{
	//color = v_Color;
	color = texture(u_Texture[int(v_TexIndex)], v_TexCoord * v_TillingFactor) * v_Color;
}