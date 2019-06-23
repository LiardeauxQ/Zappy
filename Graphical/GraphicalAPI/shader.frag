uniform sampler2D texture;
uniform vec2 u_resolution;

void main()
{
    float alpha = 0.0;
    float left = 1.0 - gl_TexCoord[0].x;
    float right = gl_TexCoord[0].x;
    float side = min(left, right);
    float ratio = min(side, 0.1);
    alpha = 1.0 - ratio;
    alpha -= 0.85;
    gl_FragColor = vec4(0.0, 0.0, 0.0, alpha);
}
