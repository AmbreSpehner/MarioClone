#version 330 core

out vec4 colour;

in vec4 myColour;
in vec2 myTexCoord;

uniform bool useTexture;
uniform sampler2D colourTexture;

uniform bool useFont;
uniform sampler2D font;
uniform vec4 fontColour;

void main()
{
	if( useTexture )
	{
		colour = texture2D( colourTexture, myTexCoord );
	}
	else if( useFont)
	{
		colour = fontColour * vec4( 1.0, 1.0, 1.0, texture( font, myTexCoord ) );
	}
	else
	{
		colour = myColour;
	}
}