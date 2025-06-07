#include "../include/EventHandler.hpp"
#include "../include/SceneHandler.hpp"

void EventHandler::update( ) {
	for ( auto obj : deadObjects_ ) {
		delete obj;
	}
	deadObjects_.clear( );

	for ( const auto& event : events_ ) {
		execute( event );
	}
	events_.clear( );
}

void EventHandler::execute( const Event& event ) {
	switch ( event.type ) {
	case EventType::CreateObject: {
		// wParam: object type
		// lParam: object pointer
		auto objType = static_cast<ObjectType>( event.wParam );
		auto objPtr = reinterpret_cast<Object*>( event.lParam );
		SceneHandler::getCurrScene( )->addObject( objType, objPtr );
		break;
	}

	case EventType::DestroyObject: {
		// lParam: object pointer
		auto objPtr = reinterpret_cast<Object*>( event.lParam );
		objPtr->setAlive( false );
		deadObjects_.push_back( objPtr );
		break;
	}

	case EventType::ChangeScene:
		// wParam: scene type
		SceneHandler::changeScene( static_cast<SceneType>( event.wParam ) );
		break;
	}
}

std::vector<Event> EventHandler::events_;
std::vector<Object*> EventHandler::deadObjects_;
