#include "PEPCH.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>

namespace Pirates
{
	void OpenGLRendererAPI::Init()
	{
		PR_PROFILE_FUNCTION();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}
	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t Width, uint32_t Height)
	{
		glViewport(x, y, Width, Height);
	}
	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexarray, uint32_t indexcount)
	{
		uint32_t count = indexcount ? vertexarray->GetIndexBuffer()->GetCount() : indexcount;
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}