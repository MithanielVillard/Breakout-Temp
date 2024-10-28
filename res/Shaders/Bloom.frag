uniform sampler2D texture;
uniform vec2 resolution;
uniform float blur_radius;

void main()
{
    vec2 texCoord = gl_TexCoord[0].xy;

    // Rayon de l'offset basé sur la résolution et le rayon du flou
    vec2 offset = blur_radius / resolution;

    // Échantillonnage autour du pixel pour créer l'effet de flou
    vec4 sum = vec4(0.0);
    sum += texture2D(texture, texCoord + vec2(-offset.x, -offset.y)) * 0.05;
    sum += texture2D(texture, texCoord + vec2(-offset.x, 0.0)) * 0.1;
    sum += texture2D(texture, texCoord + vec2(-offset.x, offset.y)) * 0.05;
    sum += texture2D(texture, texCoord + vec2(0.0, -offset.y)) * 0.1;
    sum += texture2D(texture, texCoord) * 0.4; // Pixel central (pondération plus élevée)
    sum += texture2D(texture, texCoord + vec2(0.0, offset.y)) * 0.1;
    sum += texture2D(texture, texCoord + vec2(offset.x, -offset.y)) * 0.05;
    sum += texture2D(texture, texCoord + vec2(offset.x, 0.0)) * 0.1;
    sum += texture2D(texture, texCoord + vec2(offset.x, offset.y)) * 0.05;

    gl_FragColor = sum;
}