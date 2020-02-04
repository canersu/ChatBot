#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    // GraphNode *_currentNode;
    // GraphNode *_rootNode;
    // ChatLogic *_chatLogic;
    std::shared_ptr<GraphNode> _currentNode;
    std::shared_ptr<GraphNode> _rootNode;
    std::shared_ptr<ChatLogic> _chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot &source);
    ChatBot &operator=(const ChatBot &source);
    ChatBot(ChatBot &&source);
    ChatBot &operator=(ChatBot &&source);
    ////
    //// EOF STUDENT CODE

    // getters / setters
    //void SetCurrentNode(GraphNode *node);
    void SetCurrentNode(std::shared_ptr<GraphNode> node);
    //void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetRootNode(std::shared_ptr<GraphNode> rootNode) { _rootNode = rootNode; }
    //void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    void SetChatLogicHandle(std::shared_ptr<ChatLogic> chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */