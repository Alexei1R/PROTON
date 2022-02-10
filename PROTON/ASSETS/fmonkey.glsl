#version 330 core
out vec4 FragColor;


struct Material {
    sampler2D diffuse;
    vec3 specular;
    float shininess;
}; 
uniform Material material;


struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;  




  
in vec2 Texcordinates;
in vec3 normal;
in vec3 FragPos;
uniform sampler2D tex;

uniform vec3 lcolor;
uniform vec3 lpos;
uniform vec3 camPos;




vec3 GetLight(vec3 lcolor,vec3 lpos,vec3 camPos,Material material,Light light){
	//ambiant light
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, Texcordinates));

	// diffuse light;

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lpos - FragPos);
	float diff = max( dot(norm, lightDir) , 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, Texcordinates));  


	//specular light 

	float specularStrenght = 0.2;
	vec3 viewDir = normalize(camPos - FragPos);
	vec3 reflectDir = reflect(-lightDir,norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	vec3 specular = (spec * material.specular) * light.specular;


	vec3 result = (ambient + diffuse + specular);
	return result;

}






void main()
{
	

	//FragColor = texture(tex,Texcordinates)* vec4( GetLight(lcolor, lpos, camPos, material, light) , 1.0f);
	FragColor = vec4( GetLight(lcolor, lpos, camPos, material, light) , 1.0f);
	//FragColor = vec4(Texcordinates,0.0,1.0f);
	


}