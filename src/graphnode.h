#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    //std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    //std::vector<std::shared_ptr<GraphEdge>> _parentEdges;  // edges to subsequent nodes
    ChatBot *_chatBot;
    //std::shared_ptr<ChatBot> _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    //std::shared_ptr<GraphEdge> GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    //void AddEdgeToParentNode(std::shared_ptr<GraphEdge> edge);
    //void AddEdgeToChildNode(GraphEdge *edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    //void MoveChatbotHere(ChatBot *chatbot);
    //void MoveChatbotHere(std::shared_ptr<ChatBot> chatbot);
    void MoveChatbotHere(ChatBot& chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
    //void MoveChatbotToNewNode(std::shared_ptr<GraphNode> newNode);
};

#endif /* GRAPHNODE_H_ */