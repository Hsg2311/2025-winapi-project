#include "../include/Background.hpp"
#include "../include/ResourceHandler.hpp"

#include <iostream>

namespace fs = std::filesystem;

Background::Background( const std::string& key, const std::string& fileName ) {
	// ������Ʈ ���� ��δ� Background.cpp ������ �ִ� ���(src ���͸��� ���)�� �ƴ϶�
	// D:\source\repos\2025-winapi-project\HeadSoccer\HeadSoccer -> src ���Ͽ��� �� �ܰ� ���� ���͸��� �ȴ�.
	// ���� "../assets/" ��ΰ� �ƴ϶� "assets/" ��θ� ����ؾ� �Ѵ�.

	auto filePath = fs::path( "assets/" + fileName );
	image_ = ResourceHandler::loadImage( key, fs::canonical( filePath ).string( ) );
}

void Background::render( HDC hdc ) {
	image_->draw( hdc, pos_ );
}
