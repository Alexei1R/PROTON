#version 330 core
out vec4 FragColor;
  
in vec2 TexCoord;
in vec3 normal;
in vec3 FragPos;


uniform sampler2D cubeourTexture;
uniform vec3 lcolor;
uniform vec3 lpos;
uniform vec3 camPos;




void main()
{
	//ambiant light
	float ambiantStrech = 0.1f;
	vec3 ambiant = ambiantStrech * lcolor;

	// diffuse light;

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lpos - FragPos);
	float diff = max( dot(norm, lightDir) , 0.0);
	vec3 diffuse = diff * lcolor;


	//specular light 

	float specularStrenght = 0.2;
	vec3 viewDir = normalize(camPos - FragPos);
	vec3 reflectDir = reflect(-lightDir,norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),8);
	vec3 specular = spec * lcolor;


	vec3 result = (ambiant + diffuse + specular);

	FragColor = texture(cubeourTexture,TexCoord) * vec4(result,1.0f);



	//FragColor = texture(ourTexture, TexCoord) * lcolor* (diffuse + ambient + specular);
   //FragColor = vec4(0.1,0.2,0.3,1.0) * lcolor* (diffuse + ambient + specular);
   //FragColor = lcolor;
   //FragColor = mix(texture(ourTexture, TexCoord) ,texture(ourTexture2, TexCoord) ,0.9);
}