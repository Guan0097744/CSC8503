#pragma once
#include "GameTechRenderer.h"
#include "../CSC8503Common/StateGameObject.h"
#include "../CSC8503Common/PhysicsSystem.h"
#include "../CSC8503Common/NavigationGrid.h"
#include "../CSC8503Common/PushdownState.h"

namespace NCL {
	namespace CSC8503 {

#pragma region GameStateClass

		class MenuState : public PushdownState
		{
			PushdownResult OnUpdate(float dt, PushdownState** newState) override
			{

			}
		};

		class Mode1State : public PushdownState
		{
			PushdownResult OnUpdate(float dt, PushdownState** newState) override
			{

			}
		};

		class Mode2State : public PushdownState
		{
			PushdownResult OnUpdate(float dt, PushdownState** newState) override
			{

			}
		};

		class PauseState : public PushdownState
		{
			PushdownResult OnUpdate(float dt, PushdownState** newState) override
			{

			}
		};

#pragma endregion



		class TutorialGame		{
		public:
			TutorialGame();
			~TutorialGame();

			virtual void UpdateGame(float dt);

		protected:
			void InitialiseAssets();
			void InitCamera();
			void UpdateKeys();
			void InitWorld();
			void InitGameExamples();
			void InitSphereGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, float radius);
			void InitMixedGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing);
			void InitCubeGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, const Vector3& cubeDims);
			void InitDefaultFloor();
			void BridgeConstraintTest();

#pragma region MyInit

			void InitGridMap();
			void InitSpherePlayer();
			void InitPendulum();

#pragma endregion

			bool SelectObject();
			void MoveSelectedObject();
			void DebugObjectMovement();
			void LockedObjectMovement();

			GameObject* AddOBBToWorld(const Vector3& position);
			GameObject* AddFloorToWorld(const Vector3& position);
			GameObject* AddSphereToWorld(const Vector3& position, float radius, float inverseMass = 10.0f);
			GameObject* AddCubeToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 10.0f);
			
			GameObject* AddCapsuleToWorld(const Vector3& position, float halfHeight, float radius, float inverseMass = 10.0f);

			GameObject* AddPlayerToWorld(const Vector3& position);
			GameObject* AddEnemyToWorld(const Vector3& position);
			GameObject* AddBonusToWorld(const Vector3& position);

			GameTechRenderer*	renderer;
			PhysicsSystem*		physics;
			GameWorld*			world;

			NavigationGrid*		gridMap;
			GameObject*			player;

			bool				useGravity;
			bool				inSelectionMode;

			float				forceMagnitude;

			GameObject* selectionObject = nullptr;

			OGLMesh*	capsuleMesh = nullptr;
			OGLMesh*	cubeMesh	= nullptr;
			OGLMesh*	sphereMesh	= nullptr;
			OGLTexture* basicTex	= nullptr;
			OGLShader*	basicShader = nullptr;

			//Coursework Meshes
			OGLMesh*	charMeshA	= nullptr;
			OGLMesh*	charMeshB	= nullptr;
			OGLMesh*	enemyMesh	= nullptr;
			OGLMesh*	bonusMesh	= nullptr;

			//Coursework Additional functionality	
			GameObject* lockedObject	= nullptr;
			Vector3		lockedOffset	= Vector3(0, 14, 20);
			void LockCameraToObject(GameObject* o) {
				lockedObject = o;
			}

			//Courseware StateMachine
			StateGameObject* AddStateObjectToWorld(const Vector3& position);
			StateGameObject* testStateObject = nullptr;

		};
	}
}

