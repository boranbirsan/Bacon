#include "bnpch.h"
#include "ImGuiLayer.h"

#include "Bacon/Events/Event.h"
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace Bacon
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGui Layer") {}

	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui_ImplOpenGL3_Init("#version 410");

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		

		ImGui::StyleColorsDark();
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate() 
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		//ImGui_ImplOpenGL3_NewFrame();
		//ImGui::NewFrame();

		//ImGui::Begin("Test #111111");
		//{
		//	static float f = 0.0f;
		//	float col = 0.f;
		//	int show = 1;
		//	ImGui::Text(u8"Hello, world! ");
		//	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
		//	ImGui::ColorEdit3("clear color", (float*)&col);
		//	if (ImGui::Button("Test Window")) show ^= 1;
		//	if (ImGui::Button("Another Window")) show ^= 1;
		//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		//}
		//ImVec2 v = ImGui::GetWindowSize();  // v = {32, 48} ,   is tool small
		//ImGui::Text("%f %f", v.x, v.y);

		//ImGui::End();
		//
		//ImGui::Render();
		//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Compare<ButtonPressedEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPresssed));
		dispatcher.Compare<ButtonReleasedEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleased));
		dispatcher.Compare<MouseMovedEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnMouseMoved));
		dispatcher.Compare<MouseScrolledEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnMouseScroll));
		dispatcher.Compare<KeyPressedEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnKeyPressed));
		dispatcher.Compare<KeyReleasedEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnKeyReleased));
		dispatcher.Compare<WindowResizeEvent>(BN_BIND_EVENT_FN(ImGuiLayer::OnWindowResize));
	}

	bool ImGuiLayer::OnMouseButtonPresssed(ButtonPressedEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleased(ButtonReleasedEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(event.GetX(), event.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScroll(MouseScrolledEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel = event.GetOffsetY();
		io.MouseWheelH = event.GetOffsetX();

		return false;
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[event.GetKeyCode()] = true;

		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[event.GetKeyCode()] = false;

		return false;
	}

	bool ImGuiLayer::OnWindowResize(WindowResizeEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, event.GetWidth(), event.GetHeight());

		return false;
	}
}
