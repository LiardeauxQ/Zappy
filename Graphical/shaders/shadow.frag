uniform sampler2D texture;
uniform vec2 u_resolution;

void main()
{
    float alpha = 0.0;

    float top = 1.0 - gl_TexCoord[0].y;
    float bot = gl_TexCoord[0].y;
    float side1 = min(top, bot);
    float ratio1 = min(side1, 0.2);

    float left = 1.0 - gl_TexCoord[0].x;
    float right = gl_TexCoord[0].x;
    float side2 = min(left, right);
    float ratio2 = min(side2, 0.1);

    alpha = 1.0 - ratio1;
    alpha -= 0.45;
    gl_FragColor = vec4(0.0, 0.0, 0.0, alpha);
}
