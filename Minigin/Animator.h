#pragma once
#include "BaseComponent.h"

namespace dae
{
	class RenderComponent;
	class Animator final : public BaseComponent
	{
	public:
		void PostLoad() override;
		void FixedUpdate() override;
		void AddAnimation(const int id, const int nrOffFrames, const glm::vec2& srcPos, const float srcWidth, const float srcHeight, const bool mirror = false, const float TimePerFrame = 0.250f, const bool loop = true);
		void SetAnimation(const int id);
		void SetDst(const glm::vec2& dstPos, const float dstWidth, const float dstHeight);
		void Pause();
		void Play();

	private:
		struct AnimationData
		{
			glm::vec2 SrcPos = {0.f, 0.f};
			float SrcWidth = 0.f;
			float SrcHeight = 0.f;
			float TimePerFrame = 0;
			int Id = 0;
			int NrOffFrames = 0;
			bool Mirror = false;
			bool Loop = false;
		};

		Animator(GameObject* gameObject);
		template <typename T>
		friend T* GameObject::AddComponent();

		std::vector<AnimationData> m_Animations;
		RenderComponent* m_pRenderComponent;

		// Animation info
		glm::vec2 m_DstPos;
		float m_DstWidth;
		float m_DstHeight;
		float m_ElapsedTime;
		int m_CurrentAnimationIndex;
		int m_CurrentFrame;
		bool m_Pause;
	};
}

