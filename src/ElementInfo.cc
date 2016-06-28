XmlParserUtil::ElementInfo::ElementInfo(Node& n) :
    node(n),
    type(::getElementType(n)),
    numberOfAttributes(getNumberOfAttributes(n)),
    operation(getElementOperation(n)),
    operationPosition(getElementOperationPosition(n)),
    structAttribute(false),
    name(getElementName(n)),
    content(getElementContent(n))
{}

XmlParserUtil::ElementInfo::ElementInfo(Node& n, const Com::ModelRepository::IMocPtr& parentMoc) :
    node(n),
    type(::getElementType(n)),
    numberOfAttributes(getNumberOfAttributes(n)),
    operation(getElementOperation(n)),
    operationPosition(getElementOperationPosition(n)),
    structAttribute(false),
    name(getElementName(n)),
    content(getElementContent(n))
{
    classify(parentMoc);
}

XmlParserUtil::ElementInfo::ElementInfo(Node& n, const Com::ModelRepository::IStructPtr& parentStruct) :
    node(n),
    type(::getElementType(n)),
    numberOfAttributes(getNumberOfAttributes(n)),
    operation(getElementOperation(n)),
    operationPosition(getElementOperationPosition(n)),
    structAttribute(false),
    name(getElementName(n)),
    content(getElementContent(n))
{
    classify(parentStruct);
}

XmlParserUtil::ElementInfo::ElementInfo(Node& n, const Com::ModelRepository::IActionPtr& parentAction) :
    node(n),
    type(::getElementType(n)),
    numberOfAttributes(getNumberOfAttributes(n)),
    operation(getElementOperation(n)),
    operationPosition(getElementOperationPosition(n)),
    structAttribute(false),
    name(getElementName(n)),
    content(getElementContent(n))
{
    classify(parentAction);
}
