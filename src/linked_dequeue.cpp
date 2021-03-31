#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  DoublyNode *node = new DoublyNode(e, back_, nullptr);
  if (size_ == 0) {
      front_ = node;
  } else {
      back_ = node;
  }
  back_ = node;
  size_++;
}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
  DoublyNode *node = new DoublyNode(e, nullptr, front_);
  if (size_ == 0) {
      back_ = node;
  } else {
      front_ -> previous = node;
  }
  front_ = node;
  size_++;
}

void LinkedDequeue::Dequeue() { // НЕ работает!
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
    DoublyNode *d = front_;

    if (size_ == 1) {
        delete d;
        front_ = nullptr;
        back_ = nullptr;
    } else {

        front_ = front_->next;
        front_->previous = nullptr;
        delete d;
    }
    size_--;
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  // TODO: напишите здесь свой код ...
  if (size_ > 1) {
      DoublyNode *node_to_delete = back_;
      back_ = back_ -> previous;
      delete node_to_delete;
  } else {
      delete back_;
      front_ = nullptr;
      back_ = nullptr;
  }
  size_--;
}

void LinkedDequeue::Clear() {
  // TODO: напишите здесь свой код ...
    while (size_ > 0)
        DequeueBack();
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
