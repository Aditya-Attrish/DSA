def subset_sum(nums, target, idx, current_sum):
    """
    Find a subset of numbers that sums up to the target.

    Args:
    - nums: List of integers representing the numbers to choose from.
    - target: Target sum to achieve.
    - idx: Current index in the list `nums`.
    - current_sum: Current sum of the subset.

    Returns:
    - List of integers representing the subset that sums up to the target,
      or an empty list if no such subset exists.
    """
    if idx == len(nums):
        if current_sum == target:
            return []
        return None

    for i in range(idx, len(nums)):
        if current_sum + nums[i] == target:
            return [nums[i]]
        if current_sum + nums[i] < target:
            subset = subset_sum(nums, target, i + 1, current_sum + nums[i])
            if subset is not None:
                return [nums[i]] + subset

    return None

if __name__ == "__main__":
    # Test cases
    nums = [3, 7, 4, 2, 8]
    target = 11
    subset = subset_sum(nums, target, 0, 0)
    if subset:
        print(f"Subset that sums up to {target}: {subset}")
    else:
        print("No subset found.")
