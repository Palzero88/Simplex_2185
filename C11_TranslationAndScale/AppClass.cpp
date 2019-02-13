#include "AppClass.h"
bool moveR = true;
void Application::InitVariables(void)
{
	m_cube1 = new MyMesh();

	m_cube1->GenerateCube(1.0f, C_GREEN);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//stuff that works lets the camera work
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	//move cubes x and y
	matrix4 m4TranslateUp = glm::translate(IDENTITY_M4, vector3(0.0f, 1.0f, 0.0f));
	matrix4 m4TranslateDown = glm::translate(IDENTITY_M4, vector3(0.0f, -1.0f, 0.0f));
	matrix4 m4TranslateRight = glm::translate(IDENTITY_M4, vector3(1.0f, 0.0f, 0.0f));
	matrix4 m4TranslateLeft = glm::translate(IDENTITY_M4, vector3(-1.0f, 0.0f, 0.0f));
	
	//static var for movement
	static float value = 0.0f;
	//translation for movement
	matrix4 m4TranslateMove = glm::translate(IDENTITY_M4, vector3(value, 2.0f, 3.0f));

	//increment movement back and forth
	if (moveR)
	{
		value += 0.5f;
		if (value >= 20.0f)
			moveR = false;
	}
	else if (!moveR)
	{
		value -= 0.5f;
		if (value <= -20.0f)
			moveR = true;
	}

	matrix4 m4Model = m4TranslateMove;

	//center line
	m_cube1->Render(m4Projection, m4View, m4Model);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown);

	//left of center
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp* m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateLeft);

	//right of center
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp* m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateRight);

	//right eye
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown * m4TranslateRight * m4TranslateRight);

	//left eye
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateLeft * m4TranslateLeft);

	//left of eye
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp* m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);

	//right of eye
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp* m4TranslateRight * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateRight * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown * m4TranslateRight * m4TranslateRight * m4TranslateRight);
	
	//left "arm"
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp* m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateDown);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateDown * m4TranslateDown);

	//right "arm"
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp* m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateDown);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateDown * m4TranslateDown);

	//left "mouth"
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown * m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateDown);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateLeft * m4TranslateLeft * m4TranslateDown * m4TranslateDown);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateLeft * m4TranslateDown * m4TranslateDown);

	//right "arm"
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown * m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateDown);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateRight * m4TranslateRight * m4TranslateDown * m4TranslateDown);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateDown* m4TranslateRight * m4TranslateDown * m4TranslateDown);

	//left "antanae"
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateLeft * m4TranslateLeft * m4TranslateUp);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateLeft * m4TranslateLeft * m4TranslateLeft * m4TranslateUp * m4TranslateUp);

	//right "antenae"
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateRight * m4TranslateRight * m4TranslateUp);
	m_cube1->Render(m4Projection, m4View, m4Model * m4TranslateUp * m4TranslateUp* m4TranslateRight * m4TranslateRight * m4TranslateRight * m4TranslateUp * m4TranslateUp);


	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	SafeDelete(m_cube1);

	//release GUI
	ShutdownGUI();
}