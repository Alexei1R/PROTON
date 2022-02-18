#version 330 core
out vec4 FragColor;


struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct Light {
    vec3 position;
    vec3 direction;
	float cutOff;
	float outherCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
	float linear;
	float quadratic;
	

};
uniform Material material;
uniform Light light;  

  
in vec2 Texcordinates;
in vec3 normal;
in vec3 FragPos;
uniform vec3 viewPos;










void main()
{
	
    
    
    //ambient
    vec3 ambient = light.ambient * texture(material.diffuse ,Texcordinates).rgb;
    
    //diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm,lightDir),0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse,Texcordinates).rgb;

    ////specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir,norm);
    float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
    vec3 specular = light.specular * spec * texture(material.specular,Texcordinates).rgb;

    //spetlight
    float theta = dot(lightDir,normalize(-light.direction));
    float epsilon = (light.cutOff - light.outherCutOff);
    float intensity = clamp((theta- light.outherCutOff)/epsilon ,0.0,1.0);
    diffuse *= intensity;
    specular *= intensity;


    //attenuation
    float distance = length(light.position - FragPos);
    float attenuation = 1.0/(light.constant + light.linear * distance + light.quadratic* (distance * distance));

    diffuse *= attenuation;
    ambient *= attenuation;
    specular *= attenuation;


    vec3 result = ambient + diffuse + specular;

    FragColor = vec4(result,1.0f);

    





}