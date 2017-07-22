#include "TriangleShape.h"

#include <vector>

#include <iostream>

TriangleShape::TriangleShape( const glm::vec3 & vertPos1, const glm::vec3 & vertPos2, const glm::vec3 & vertPos3, const glm::vec4& colour )
	:
	m_VertPos1( vertPos1 ),
	m_VertPos2( vertPos2 ),
	m_VertPos3( vertPos3 ),
	m_Colour( colour ),
	m_CurrentType( ShapeType::FILLED )
{
	std::vector<GLfloat> vertices =
	{
		m_VertPos1.x, m_VertPos1.y, m_VertPos1.z,
		m_VertPos2.x, m_VertPos2.y, m_VertPos2.z,
		m_VertPos3.x, m_VertPos3.y, m_VertPos3.z
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );
}

TriangleShape::TriangleShape( const glm::vec3 & vertPos1, const glm::vec3 & vertPos2, const glm::vec3 & vertPos3, const glm::vec4 & colour, int type )
	:
	TriangleShape( vertPos1, vertPos2, vertPos3, colour )
{
	m_CurrentType = type;
}

void TriangleShape::Render( )
{
	m_VAO.Bind( );

	std::cout << m_CurrentType << '\n';

	if( m_CurrentType == ShapeType::FILLED )
	{
		glDrawArrays( GL_TRIANGLES, 0, 3 );
	}
	if( m_CurrentType == ShapeType::LINE )
	{
		glDrawArrays( GL_LINE_LOOP, 0, 3 );
	}
}

void TriangleShape::SetShapeType( int type )
{
	m_CurrentType = type;
}