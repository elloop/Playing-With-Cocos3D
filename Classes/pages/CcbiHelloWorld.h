#ifndef PLAYING_WITH_COCOS3D_PAGE_CCB_HELLOWORLD_H
#define PLAYING_WITH_COCOS3D_PAGE_CCB_HELLOWORLD_H

#include "cocos2d.h"
#include "cocosbuilder/CocosBuilder.h"

class CcbiHelloWorld : public cocos2d::Node
{
public:
    CREATE_FUNC(CcbiHelloWorld);
    bool init() override
    {
        using cocosbuilder::NodeLoaderLibrary;
        using cocosbuilder::CCBReader;

        // ��һ���� ����һ��NodeLoaderLibrary
        auto loaderLib = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();

        // �ڶ���: ����CCBReader
        auto ccbReader = new CCBReader(loaderLib);

        // �������� ����CCBReader��readNodeGraphFromFile�ķ���������ccbi����
        auto node = ccbReader->readNodeGraphFromFile("ccbi/baozao.ccbi", this);
        ccbReader->release();

        // ������ϣ�����ʹ��Node�ˡ�
        if ( node )
        {
            addChild(node);
        }
        return true;
    }
};

#endif  //PLAYING_WITH_COCOS3D_PAGE_CCB_HELLOWORLD_H