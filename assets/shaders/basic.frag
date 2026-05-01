#version 330 core

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightDir;   // direzione luce (normalizzata)
uniform vec3 lightColor;
uniform vec3 objectColor;

out vec4 FragColor;

void main()
{
    vec3 N = normalize(Normal);
    vec3 L = normalize(-lightDir);

    float diff = max(dot(N, L), 0.0);

    vec3 result = diff * lightColor * objectColor;

    FragColor = vec4(result, 1.0);
}