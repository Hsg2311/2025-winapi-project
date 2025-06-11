#include "../include/Background.hpp"
#include "../include/ResourceHandler.hpp"
#include "../include/Camera.hpp"

#include <iostream>

Background::Background( const std::string& key, const std::string& fileName, bool premultipliedAlpha ) {
	// ������Ʈ ���� ��δ� Background.cpp ������ �ִ� ���(src ���͸��� ���)�� �ƴ϶�
	// D:\source\repos\2025-winapi-project\HeadSoccer\HeadSoccer -> src ���Ͽ��� �� �ܰ� ���� ���͸��� �ȴ�.
	// ���� "../assets/" ��ΰ� �ƴ϶� "assets/" ��θ� ����ؾ� �Ѵ�.

	auto filePath = fs::path( "assets/" + fileName );
	image_ = ResourceHandler::loadImage( key, fs::canonical( filePath ).string( ), premultipliedAlpha );
}

void Background::render( HDC hdc ) {
	auto cameraPos = Camera::getPos( );
	auto relativePos = pos_ - cameraPos;

	image_->draw( hdc, relativePos );

	componentRender( hdc );
}
